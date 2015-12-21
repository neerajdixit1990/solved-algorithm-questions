import java.io.*;
class wc {
    public wc() {
    }
    public static void main(String args[]) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String input;
        int test_cases,i,j,len=0,currlength=0,maxlength=-1,no_words=0,group_length=1,flag=0;
        input= br.readLine();
        test_cases=Integer.parseInt(input);
	for(i=1;i<=test_cases;i++)
	{   	len=0;
		flag=0;
		currlength=0;
                		maxlength=-1;
                		no_words=0;
		group_length=1;
                		input= br.readLine();
                		len=input.length();
		if(len==0)
			System.out.println(0);
		else
		{
                			for(j=0;j<len;j++)
               			{
				if(input.charAt(j)!=' '&&flag==0)
					flag=1;
                       			if(input.charAt(j)==' '&&flag==1)
				{
					if(no_words==currlength&&no_words!=0)
						group_length++;
					else if(no_words!=currlength&&no_words!=0)
					{
						currlength=no_words;
						if(group_length>maxlength)
							maxlength=group_length;
						group_length=1;
					}
					no_words=0;
				}
				else if(input.charAt(j)!=' ')
					no_words++;	
        			}
			if(flag==1)
			{
				if(no_words==currlength)
					group_length++;
				if(group_length>maxlength)
					maxlength=group_length;
        				System.out.println(maxlength);
			}
			else
				System.out.println(0);
		}
    	}
    }
}
