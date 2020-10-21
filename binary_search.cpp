
/* IMP NOTE that in binary Search, 
* mid always rounds down which can cause infinite loops if lo is not adjusted properly
* therfore always adjust lo to mid+1 and not mid
*/


int lo = 0,hi = (int)(1e9),mid;
while(lo<hi) // ?? <  or <=
{
    mid = lo + (hi-lo)/2;
    if(chk(height,i,mid))
    {
        // ans = mid;
        lo = mid+1;  
    }
    else hi = mid;
    
}