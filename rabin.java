package mathforis;

import java.util.*;
public class rabin{
public static int isPrimeNumber(int number){ //判断是否为素数
double num=(double)number;
int n=(int)Math.sqrt(num);
int sign=2;
for(int i=2;i<=n;i++){
if(number%i==0)
break;
sign++;
}
if(sign>=n)
return 1;
else
return 0;
}

public static int isMode(int number){    //判断结果是否模4余3
if(number%4==3)
return 1;
else
return 0;
}

public static int PrimeNumberTest(int max,int min){   //在max与min范围内产生随机数
Random rand=new Random();
int m=rand.nextInt(max)%(max-min+1)+min;
// int m=(int)Math.rint(Math.random()*(max-min)+min);
int judge1=isPrimeNumber(m);  //判断是否是素数
if(judge1==0){
int p=max;
int q=min;
return PrimeNumberTest(p,q);
}

int judge2=isMode(m);//判断是否模4余3
if(judge2==0){
int p=max;
int q=min;
return PrimeNumberTest(p,q);
}
return m;
}

public static int opposite(int a,int b){     //求a相对于b的逆
int i=0;
while(a*(++i)%b!=1);
return i;
}

public static int Deciphering(int b1,int b2,int m1,int m2){  //中国剩余定理求解
int m=m1*m2;
int M1=m2;
int M2=m1;
int M11=opposite(M1,m1);
int M22=opposite(M2,m2);
int result=(M11*M1*b1+M22*M2*b2)%m;
return result;
}

public static void main(String[] args) throws Exception{ 
System.out.println("请输入需要素数的所在区间");
Scanner input=new Scanner(System.in);
int min=input.nextInt();
int max=input.nextInt();
       int p=PrimeNumberTest(max,min);
// int p=7;
    int q=PrimeNumberTest(max,min);
// int q=11;
int n=p*q;
System.out.println("请输入明文数字：");
int plaintext=input.nextInt();
int encrytext=(plaintext*plaintext)%n;
System.out.println("加密以后的密文为：");
System.out.println(encrytext);
//解密的过程
System.out.println("解密后明文所在的集合为：");
int c1=0,c2=0;
c1=(int)Math.pow(encrytext, (p+1)/4)%p;
c2=(int)Math.pow(encrytext, (q+1)/4)%q;
int finaltext1=Deciphering(c1,c2,p,q);
System.out.println(finaltext1);
c1=p-(int)Math.pow(encrytext, (p+1)/4)%p;
c2=(int)Math.pow(encrytext, (q+1)/4)%q;
int finaltext2=Deciphering(c1,c2,p,q);
System.out.println(finaltext2);
c1=(int)Math.pow(encrytext, (p+1)/4)%p;
c2=q-(int)Math.pow(encrytext, (q+1)/4)%q;
int finaltext3=Deciphering(c1,c2,p,q);
System.out.println(finaltext3);
c1=p-(int)Math.pow(encrytext, (p+1)/4)%p;
c2=q-(int)Math.pow(encrytext, (q+1)/4)%q;
int finaltext4=Deciphering(c1,c2,p,q);
System.out.println(finaltext4);
input.close();


}
}