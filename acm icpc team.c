int main(){
    int n, m; 
    scanf("%d %d",&n,&m);
    char c[n][m];
    for(int i = 0; i < n; i++)
       scanf("%s",c[i]);
    int s1, maximum = 0, answer = 0;
    for(int i = 0; i < n-1; i++) 
    {
        for(int j = i+1; j < n; j++) 
        {
            s1 = 0;
            for(int k = 0; k < m; k++) 
                if(c[i][k] == '1' || c[j][k] == '1')
                    s1++;
            if(maximum < s1)
            {
                maximum = s1;
                answer = 1;
            }
            else if(maximum == s1)
                answer++;
        }
    }
    printf("%d\n%d\n", maximum, answer);
    return 0;
}
