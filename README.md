# ponderada-de-sala-4

Neste exercicio foi montado um circuito simples de semáforo utilizando o Arduino, LEDs e resistores. O objetivo foi simular o funcionamento das luzes de trânsito (vermelho, amarelo e verde) controladas por meio de programação, permitindo compreender o uso de saídas digitais e temporização no Arduino.

## materiais: 

| **Item**              | **Descrição / Observação**         | **Quantidade** |
|------------------------|------------------------------------|----------------|
| LED                   | Diodo emissor de luz     | 3 unidades     |
| Resistores 330 Ω       | Resistores para limitação de corrente | 4 unidades     |
| Buzzer                | Emissor sonoro piezoelétrico       | 1 unidade      |
| Protoboard            | Protoboard 830 pontos              | 1 unidade      |
| Jumpers               | Cabos de conexão diversos          | Diversos       |
| Arduino               | Placa microcontroladora (UNO) | 1 unidade      |


## codigo:

``` c++
int x = 10;
int* p = &x;
#define BUZZER *p

class LED {
	int LredC;
	int LyelC;
	int LgreC;

public:
  LED (int LrC, int LyC, int LgrC) {

  LredC = LrC;
	LyelC = LyC;
	LgreC = LgrC;
    
  pinMode(LredC, OUTPUT);
  pinMode(LyelC, OUTPUT);
  pinMode(LgreC, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  }
  void apita () {
  digitalWrite(LredC, HIGH);
  delay(6000); 

  digitalWrite(LyelC, HIGH);
  digitalWrite(LredC, LOW);
  delay(2000); 

  digitalWrite(LyelC,LOW);
  digitalWrite(LgreC, HIGH);
  tone(BUZZER, 392);
  delay(4000);

  digitalWrite(LgreC, LOW);
  noTone(BUZZER);
  }
};

LED leds(13, 12, 11);

void setup()
{}

void loop()
{
	leds.apita();
}
```
### Explicação do código:

O código cria uma classe chamada LED para controlar as luzes do semáforo e o buzzer. No construtor, são definidos os pinos usados para os LEDs vermelho, amarelo e verde, além do pino do buzzer, configurando todos como saídas.
Na função apita(), o programa acende cada LED em sequência, simulando as fases do semáforo: primeiro o vermelho (pare), depois o amarelo (atenção) e, por fim, o verde (siga), que é acompanhado de um som gerado pelo buzzer.
A função loop() chama leds.apita() continuamente, fazendo o ciclo se repetir de forma automática.

## video de demonstração:

link do video de demonstração: [link](https://drive.google.com/file/d/1_r24__aUyEt4-2PgSn_q55IxkWEnfr8n/view?usp=sharing)
