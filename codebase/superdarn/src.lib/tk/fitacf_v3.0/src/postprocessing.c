/*Copyright (C) 2016  SuperDARN Canada

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

/*
ACF Processing main functions

Marina Schmidt
ISAS
May 2018

*/

#include "rtypes.h"
#include "postprocessing.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>



/*
 * vertical_streak_removal:
 * Code for eliminating vertical noise-like "streaks" in  SuperDARN data.
 * These "streaks" are most probably cause by strong lightning discharges.
 * Theis most prominent feature is that the velocity vs range dependence
 * shows a saw-tooth pattern with the velocity growing linearly until it
 * reaches its maximum measurable value, v_max, and then "wrapping" to the same one
 * but with the opposite sign.
 * 
 * The saw-tooth pattern is recognised by finding the sharp jumps between
 * the velocity measurements at cosecutive range gates. If the difference
 * exceed a certain threshold (e.g. v_max), the whole beam record should be discarded,
 *  i.e. quality flags across all range gates should be set to 0.
 *  The same has to be done to all other fitted paramters.
 */

void vertical_streak_remove(FITPRMS *fit_prms, struct FitData* fit_data, struct FitRange* fit_range_array)
{
    /* I am assuming a node is a record of data? */
    int i = 0;
    double c = 299792458; /* speed of light */
    double v_max=0;
    double dv_max=-9999;
    int inx = 0;  
    double dv_cur = 0.0;

    /* Calculate the maximum possible velocity value for this record */
    v_max = c / (4*fit_prms->mpinc * 1e-6 * fit_prms->tfreq*1e3);

    /* Calculate velocity "derivative" across consective range gates */
    for(i=0; i < fit_prms->nrang-1; i++)
    {
        dv_cur = fit_range_array[i].v - fit_range_array[i+1].v;
        if(dv_cur > dv_max) 
        {
            dv_max = dv_cur;
            inx = i;
        }
    }
    if((dv_max > v_max) && (fit_prms->pwr0[inx] > 2.0))
    {

        fprintf(stderr,"zero the data at %d:%d on range gate:  %d for beam: %d \n",fit_prms->time.hr,fit_prms->time.mt,inx,fit_prms->bmnum);
        for (i=0; i < fit_prms->nrang-1; i++)
        {
            fit_range_array[i].qflg=0;
            fit_range_array[i].v=0;
            fit_range_array[i].v_err=0;
            fit_range_array[i].w_l_err=0;
            fit_range_array[i].p_l=0;
            fit_range_array[i].p_l_err=0;
            fit_range_array[i].w_s=0;
            fit_range_array[i].w_s_err=0;
            fit_range_array[i].p_s=0;
            fit_range_array[i].p_s_err=0;
            fit_data->elv[i].normal=0;
            fit_data->elv[i].high=0;
            fit_data->elv[i].low=0;
        }
    }
    
}
