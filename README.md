# PthreadsPT2
Resultado Cmm Mutex
![image](https://github.com/Gugrggg/Pthreads/assets/124708512/a9a5784e-2227-4518-ba79-d56f5931fddc)



Resultado Sem Mutex
![image](https://github.com/Gugrggg/Pthreads/assets/124708512/320baf42-31a2-492d-b186-6a912e50a778)

Diferenças:

A principal diferença entre eles é o uso de um mutex no primeiro código para controlar o acesso à variável compartilhada sum. Essa diferença na sincronização é crucial para entender as divergências nos valores de 
π calculados por cada versão.

Divergencias:

Com Mutex: O acesso à variável sum é sincronizado usando um mutex. Isso garante que apenas uma thread por vez possa atualizar sum, resultando em um cálculo preciso e consistente de 𝜋 π.

Sem Mutex: Múltiplas threads podem tentar atualizar sum ao mesmo tempo sem qualquer coordenação. Isso pode causar sobreposições na escrita, onde as atualizações de uma ou mais threads podem ser perdidas. O resultado final de sum pode ser menor do que deveria, afetando a precisão do valor calculado de 𝜋

As duas divergências acima ocorrem devido à maneira como operações concorrentes são manejadas em ambientes multithread. Sem mecanismos de proteção adequados, como mutexes, as threads operam com uma visão incompleta e descoordenada
