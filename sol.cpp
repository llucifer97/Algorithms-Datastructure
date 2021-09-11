

bool coprime(int a, int b) {
     
    if ( __gcd(a, b) == 1)
        return true;
    else
        return false;    
}




int find(int input1[],int input2)
{
	for (int i = 0; i < input2 - 1 ; i++ )
	{
		if(coprime(input1[i],input1[i+1]) && (input1[i] > input1[i+1] ))
		{
			return i;
		}
	}

}
