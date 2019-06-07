#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int AC = 0;
    int MQ = 0;
    int MAR = 0;
    int MBR[11];
    int PC = 0;
    int IR[11];
    int opcode = 0;

    int a=0;
    int p=9;
    int temp=0;
    int temp1[32];
    int temp2[16];
    int temp3[16];
    int resulmul;
    int c;

    //começo instruções
    int bloco1 [1024][11] = {001001 , 1,0,0,1,0,1,1,0,1,0, //LOAD MQ, 602
                            001011 , 1,0,0,1,0,1,1,0,0,1, //MUL 601
                            001010 , 0,0,0,0,0,0,0,0,0,0, //LOAD MQ
                            000101 , 1,0,0,1,0,1,1,0,0,0, //ADD 600
                            100001 , 1,0,0,1,0,1,1,1,1,1, //STOR 607
                            001001 , 1,0,0,1,0,1,1,1,0,0, //LOAD MQ, 604
                            001011 , 1,0,0,1,0,1,1,1,0,1, //MUL 605
                            001010 , 0,0,0,0,0,0,0,0,0,0, //LOAD MQ
                            100001 , 1,0,0,1,1,0,0,0,0,0, //STOR 608
                            000001 , 1,0,0,1,0,1,1,0,1,1, //LOAD 603
                            000110 , 1,0,0,1,1,0,0,0,0,0, //SUB 608
                            100001 , 1,0,0,1,1,0,0,0,0,1, //STOR 609
                            000001 , 1,0,0,1,0,1,1,0,1,1, //LOAD 603
                            000110 , 1,0,0,1,1,0,0,0,0,0, //SUB 608
                            100001 , 1,0,0,1,1,0,0,0,0,1, //STOR 609
                            000001 , 1,0,0,1,0,1,1,1,1,1, //LOAD 607
                            001100 , 1,0,0,1,1,0,0,0,0,1, //DIV 609
                            100001 , 1,0,0,1,0,1,1,1,1,1, //STOR 607
                            001010 , 0,0,0,0,0,0,0,0,0,0, //LOAD MQ
                            100001 , 1,0,0,1,0,1,1,1,1,0};//STOR 606

                            bloco1[600][0] = 37;
                            bloco1[601][0] = 80;
                            bloco1[602][0] = 23;
                            bloco1[603][0] = 16;
                            bloco1[604][0] = 63;
                            bloco1[605][0] = 11;

    for(PC = 0 ; PC <=1023;PC++){
        a = 0;

        for (a = 0; a<=10;a++){
            MBR[a] = bloco1[PC][a]; //MBR lê a intrução no bloco de memória
            IR[a] = MBR[a]; //Essa instrução é copiada para IR
        }

        opcode = IR[0];  //IR é dividido em opcode e endereço (MAR)
       if(opcode == 001010){ //LOAD MQ
            //o AC recebe o conteúdo de MQ
            AC = MQ;
            cout<< "LOAD MQ "<<endl;
            cout<< "    AC = " << AC << endl;
        }

       if(opcode == 001001){  //LOAD MQ, X

           //transforma endereço em decimal
            p=9;
            MAR = 0;
            for(int j = 1; j <= 10; j++){
                c = bloco1[PC][j];

                MAR += c*pow(2,p);
                p--;
            }

            //MQ recebe o conteúdo do enderço "end"
            cout << "LOAD MQ, "<<MAR <<endl;
            MQ = bloco1[MAR][0];
            cout <<"    MQ = "<< MQ << endl;
        }

        if (opcode == 100001){ //STOR X
            //transforma endereço em decimal
            MAR = 0;
            p = 9;
            for(int j = 1; j <= 10; j++){
                c = bloco1[PC][j];
                MAR += c*pow(2,p);
                p--;
            }

            //transfere o que tem em AC para a memória de enreço "end"
            bloco1[MAR][0] = AC;
            cout <<"STOR "<<MAR <<endl;
            cout <<"    R["<<MAR<<"] = " << bloco1[MAR][0]<<endl;
        }

        if(opcode == 000001){ //LOAD X
            //transforma endereço em decimal
            MAR = 0;
            p=9;
            for(int j = 1; j <= 10; j++){
                c = bloco1[PC][j];
                MAR += c*pow(2,p);
                p--;
            }

            //transfere o conteúdo da memória de endereço end para AC
            AC = bloco1[MAR][0];
            cout << "LOAD "<<MAR<<endl;
            cout << "   AC = "<<AC<<endl;
        }

        if(opcode == 000101) { //ADD X
            //transforma endereço em decimal
            MAR = 0;
            p = 9;
            for(int j = 1; j <= 10; j++){
                c = bloco1[PC][j];
                MAR += c*pow(2,p);
                p--;
            }

            //AC recebe a soma do próprio AC com o valor contido no endereço end
            AC += bloco1[MAR][0];
            cout << "ADD "<<MAR<<endl;
            cout << "   AC = "<<AC<<endl;
        }

        if(opcode == 000110){ //SUB X
            //transforma endereço em decimal
            MAR = 0;
            p=9;
            for(int j = 1; j <= 10; j++){
                c = bloco1[PC][j];
                MAR += c*pow(2,p);
                p--;
            }

            //AC recebe a diferença entre o próprio AC e o valor contido no endereço end
            AC -= bloco1[MAR][0];
            cout << "SUB "<<MAR<<endl;
            cout << "   AC = "<<AC<<endl;
        }

        if(opcode == 001011){ //MUL X

            //converte de binário para intebloco1o
            MAR = 0;
            p=9;
            for(int j = 1; j <= 10; j++){
                c = bloco1[PC][j];
                MAR += c*pow(2,p);
                p--;
            }
            cout <<"MUL  " <<MAR<<endl;

            //realiza a mutiplicação
            resulmul = MQ * bloco1[MAR][0];

            //converte novamente para binário
            //mas agora com 32 posições por causa da mutiplicação
            temp = resulmul;
            for(int i = 31; i >= 0 ; i--){
                if (temp%2 == 0){
                    temp1[i] = 0;
                }
                if (temp%2 != 0){
                    temp1[i] = 1;
                }
                temp = temp/2;

            }
            //salva os 16 bits mais significativos no vetor temp2
            //salva os 16 bits menos significativos no vetor temp3
            for (int i = 0 ;i <= 15; i++){
                temp2[i] = temp1[i];
                temp3[i] = temp1[i+16];
            }

            int pt1 = 0;
            int pt2 = 0;
            p=15;
            //transforma novamente em intebloco1o
            for(int j = 0; j <= 15; j++){
                c = temp2[j];
                pt1 += c*pow(2,p);
                p--;
            }

            p=15;
            //transforma novamente em intebloco1o
            for(int j = 0; j <= 15; j++){
                c = temp3[j];
                pt2 += c*pow(2,p);
                p--;
            }

            //salva os bits mais significativos no AC
            //salva os bits menos significativos no MQ
            AC = pt1;
            MQ = pt2;
            cout <<"    AC = "<< AC <<endl;
            cout <<"    MQ = "<< MQ <<endl;
        }

        if(opcode == 001100){ //DIV X
            //transforma em decimal
            MAR = 0;
            p = 9;
            for(int j = 1; j <= 10; j++){
                c = bloco1[PC][j];
                MAR += c*pow(2,p);
                p--;
            }
            MQ = AC/bloco1[MAR][0];
            AC = AC%bloco1[MAR][0];

            cout << "DIV "<<MAR<<endl;
            cout << "   MQ = "<<MQ<<endl;
            cout << "   AC = "<<AC<<endl;
        }
    }
    return 0;
}
