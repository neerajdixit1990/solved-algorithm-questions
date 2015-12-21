import java.io.*;
import java.util.*;
class LQDCANDY {
    
    
    public LQDCANDY() {
    }
    public static void main(String args[]) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String dummy;
        long test_cases,input,i,barlength,min_cut,j,count,min_len,temp,result;
        dummy= br.readLine();
        test_cases=Long.parseLong(dummy);
        for(i=1;i<=test_cases;i++)
        {
            dummy= br.readLine();
            input=Long.parseLong(dummy);
            
            if((input&(input-1))==0)
            {
                System.out.println(input + " 0");
            }
            else
            {
                temp=4611686018427387904L;          // 2^62
                count=0;
            
                while(temp!=0)              // logarithm
                {
                    count++;
                    result=temp&input;
                    if(result!=0)
                        break;
                    temp=temp>>1;
                }
                barlength=63-count;
                barlength++;
            
                temp=1;
                count=0;
                while(true)
                {
                    result=input & temp;
                    if(result!=0)
                        break;
                    temp=temp<<1;
                    count++;
                }
                System.out.println((1<<barlength) + " " + (barlength-count));
            }
        }
    }
}
