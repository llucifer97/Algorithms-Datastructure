

int find(int input1[],int input2)
{
	for (int i = 0; i < input2 - 1 ; i++ )
	{
		

		bool flag1 = false,flag2 = false;

		 if ( __gcd(input1[i],input1[i+1]) == 1)flag1 = true;

		 if (input1[i] > input1[i+1]) flag2 = true;

		 if(flag1 && flag2)
		 {
			 return i;
		 }


	}
return -1;
}
