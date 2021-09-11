

int fun(int input1,string input2[])
{
	set<string> s;
	for(int i = 0;i<input1;i++)
	{
		string temp = "";
		string str = input2[i];
		for(int j =0;j<str.size();j++)
		{
			if(i%2 == 0)
			{
				temp += to_string(j);
			}
		}
		s.insert(temp);
	}
	return s.size();
}
