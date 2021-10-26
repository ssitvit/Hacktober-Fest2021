import java.io.*;

public class slotmachine {
    public static void main(String args[])throws Exception
    { 
        BufferedReader in=new BufferedReader( new InputStreamReader(System.in));
        System.out.println("enter 1 to start slot machine");
        int input=Integer.parseInt(in.readLine());
       int z;
        if(input==1)
        {
            do
            {
            String[][] x= new String[3][3];
            for(int a=1;a<=15;a++)
            {
                for(int b=0;b<=2;b++)
                {
                 x[2][b]=x[1][b];
                 x[1][b]=x[0][b];
                 long r=Math.round((Math.random()*10)%3);
                 if(r==0)
                 x[0][b]="platinum";
                 else if(r==1)
                 x[0][b]="  gold  ";
                 else
                 x[0][b]=" silver ";
                }
                 for(int c=0;c<=2;c++)
                 {
                 Thread.sleep(500);
                    System.out.println("\u000c");
                 System.out.println(" "+x[0][0]+" "+x[0][1]+" "+x[0][2]+" ");
                 System.out.println(">"+x[1][0]+" "+x[1][1]+" "+x[1][2]+"<");
                 System.out.println(" "+x[2][0]+" "+x[2][1]+" "+x[2][2]+" ");
                }
            }
            if(x[1][0]==x[1][1]&&x[1][1]==x[1][2])
            System.out.println("You win jackpot of "+x[1][1]);
            else if(x[1][0]!=x[1][1]&&x[1][1]!=x[1][2])
            System.out.println("You win nothing");
            else
            {
                if(x[1][1]==x[1][0])
                System.out.println("you win two of "+x[1][1]);
                else
                System.out.println("You win two of "+x[1][2]);
            }
            System.out.println("enter 1 to start again, any other no. to quit");
           z =Integer.parseInt(in.readLine());
        }while(z==1);
    }
 System.out.println("\u000c");
}
}
    
