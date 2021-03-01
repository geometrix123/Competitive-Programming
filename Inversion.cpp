ll getSum(ll BITree[], ll index)
{
    ll sum = 0;
    while (index > 0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}
void updateBIT(ll BITree[], ll n, ll index, ll val)
{
    while (index <= n)
    {
       BITree[index] += val;
       index += index & (-index);
    }
}
void convert(ll arr[], ll n)
{
    ll temp[n];
    for (ll i=0; i<n; i++)
        temp[i] = arr[i];
    sort(temp, temp+n);
 
    for (ll i=0; i<n; i++)
    {
        arr[i] = lower_bound(temp, temp+n, arr[i]) - temp + 1;
    }
}
ll getInvCount(ll arr[], ll n)
{
    ll invcount = 0;
    convert(arr, n);
    ll BIT[n+1];
    for (ll i=1; i<=n; i++)
        BIT[i] = 0;

    for (ll i=n-1; i>=0; i--)
    {
        invcount += getSum(BIT, arr[i]-1);
        updateBIT(BIT, n, arr[i], 1);
    }
 
    return invcount;
}

