/* depends on:
 * stdio.h, stdlib.h, math.h, string.h, time.h*/

/* macros and typedefs */

/* enumerations, structs, unions */

/* function definitions */
internal real32 normal_distribution(real32 x, real32 mu, real32 sigma);

/* function implementations */
internal real32
normal_distribution(real32 x, real32 mu, real32 sigma)
{
        return pow(e32,-pow((x - mu)/sigma,2)/2)/(sigma*sqrt(2*pi32));
}
