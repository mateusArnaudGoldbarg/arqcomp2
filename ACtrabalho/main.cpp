#include <iostream>
#include <math.h>

using namespace std;

int load_mq ();
int load_mqx();
int stor_x();
int load_x();
int add_x();
int sub_x();
int mul_x();
int div_x();
int conv_bin();


int main()
{
    int c;
    int acc;
    int MQ;
    int end = 0;
    int p=9;

    //começo instruções
  int bloco1[1024][2] =    {001001 , 1001011010, //LOAD MQ, 602
                            001011 , 1001011001, //MUL 601
                            001010 , 0000000000, //LOAD MQ
                            000101 , 1001011000, //ADD 600
                            100001 , 1001011111, //STOR 607
                            001001 , 1001011100, //LOAD MQ, 604
                            001011 , 1001011101, //MUL 605
                            001010 , 0000000000, //LOAD MQ
                            100001 , 1001100000, //STOR 608
                            000001 , 1001011011, //LOAD 603
                            000110 , 1001100000, //SUB 608
                            100001 , 1001100001, //STOR 609
                            000001 , 1001011111, //LOAD 607
                            000110 , 1001100000, //SUB 608
                            100001 , 1001100001, //STOR 609
                            000001 , 1001011111, //LOAD 607
                            001100 , 1001100001, //DIV 609
                            100001 , 1001011111, //STOR 607
                            001010 , 0000000000, //LOAD MQ
                            100001 , 1001011110};//STOR 606

    bloco1[600][0] = 37;
    bloco1[601][0] = 80;
    bloco1[602][0] = 23;
    bloco1[603][0] = 16;
    bloco1[604][0] = 63;
    bloco1[605][0] = 11;

    int bloco2[1024][10] = { 1,0,0,1,0,1,1,0,1,0, //LOAD MQ, 602
                         1,0,0,1,0,1,1,0,0,1, //MUL 601
                         0,0,0,0,0,0,0,0,0,0, //LOAD MQ
                         1,0,0,1,0,1,1,0,0,0, //ADD 600
                         1,0,0,1,0,1,1,1,1,1, //STOR 607
                         1,0,0,1,0,1,1,1,0,0, //LOAD MQ, 604
                         1,0,0,1,0,1,1,1,0,1, //MUL 605
                         0,0,0,0,0,0,0,0,0,0, //LOAD MQ
                         1,0,0,1,1,0,0,0,0,0, //STOR 608
                         1,0,0,1,0,1,1,0,1,1, //LOAD 603
                         1,0,0,1,1,0,0,0,0,0, //SUB 608
                         1,0,0,1,1,0,0,0,0,1, //STOR 609
                         1,0,0,1,0,1,1,0,1,1, //LOAD 603
                         1,0,0,1,1,0,0,0,0,0, //SUB 608
                         1,0,0,1,1,0,0,0,0,1, //STOR 609
                         1,0,0,1,0,1,1,1,1,1, //LOAD 607
                         1,0,0,1,1,0,0,0,0,1, //DIV 609
                         1,0,0,1,0,1,1,1,1,1, //STOR 607
                         0,0,0,0,0,0,0,0,0,0, //LOAD MQ
                         1,0,0,1,0,1,1,1,1,0};//STOR 606

    for(int PC = 0 ; PC <=1023;PC++){
       if(bloco1[PC][0] == 001010){ //LOAD MQ
            acc = MQ;
            cout<< "LOAD MQ "<<endl;
            cout<< "    AC = " << acc << endl;
        }

       if(bloco1[PC][0] == 001001){  //LOAD MQ, X
            int p=9;
            int end = 0;
            for(int j = 0; j <= 9; j++){
                c = bloco2[PC][j];

                end += c*pow(2,p);
                p--;
            }
            cout << "LOAD MQ, "<<end <<endl;
            MQ = bloco1[end][0];
            cout <<"    MQ = "<< MQ << endl;
        }

        if (bloco1[PC][0] == 100001){ //STOR X
            int end = 0;
            int p = 9;
            for(int j = 0; j <= 9; j++){
                c = bloco2[PC][j];
                end += c*pow(2,p);
                p--;
            }
            bloco1[end][0] = acc;
            cout <<"STOR "<<end <<endl;
            cout <<" R["<<end<<"] = " << bloco1[end][0]<<endl;
        }

        if(bloco1[PC][0] == 000001){ //LOAD X
            int end = 0;
            int p=9;
            for(int j = 0; j <= 9; j++){
                c = bloco2[PC][j];
                end += c*pow(2,p);
                p--;
            }
            acc = bloco1[end][0];
            cout << "LOAD "<<end<<endl;
            cout << "   AC = "<<acc<<endl;
        }

        if(bloco1[PC][0] == 000101) { //ADD X
            int end = 0;
            int p = 9;
            for(int j = 0; j <= 9; j++){
                c = bloco2[PC][j];
                end += c*pow(2,p);
                p--;
            }
            acc += bloco1[end][0];
            cout << "ADD "<<end<<endl;
            cout << "   AC = "<<acc<<endl;
        }

        if(bloco1[PC][0] == 000110){ //SUB X
            int end = 0;
            int p=9;
            for(int j = 0; j <= 9; j++){
                c = bloco2[PC][j];
                end += c*pow(2,p);
                p--;
            }
            acc -= bloco1[end][0];
            cout << "SUB "<<end<<endl;
            cout << "   AC = "<<acc<<endl;
        }

        if(bloco1[PC][0] == 001011){ //MUL X
            int end = 0;
            int p=9;
            for(int j = 0; j <= 9; j++){
                c = bloco2[PC][j];
                end += c*pow(2,p);
                p--;
            }
            cout <<"MUL  " <<end<<endl;
            acc = MQ * bloco1[end][0];
            MQ = acc;
            cout << "   AC = " << acc <<endl;
        }

        if(bloco1[PC][0] == 001100){ //DIV X
            int end = 0;
            int p = 9;
            for(int j = 0; j <= 9; j++){
                c = bloco2[PC][j];
                end += c*pow(2,p);
                p--;
            }
            MQ = acc/bloco1[end][0];
            cout << "DIV "<<end<<endl;
            cout << "   MQ = "<<MQ<<endl;
        }
    }
    return 0;
}
