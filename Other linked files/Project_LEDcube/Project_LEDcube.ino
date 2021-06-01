int Column[16] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, A5, A4};  // maak een lijst aan voor kolommen 
int Layer[4] = {A3, A2, A1, A0};  // maak een lijst aan voor de lagen


void setup() {
  // put your setup code here, to run once
  for (int i = 0; i < 16; i++) 
  {
    pinMode(Column[i], OUTPUT);  // initialiseer alle kolommen als output d.m.v een for-loop 
  }
  //setting layers to output
  for (int i = 0; i < 4; i++)
  {
    pinMode(Layer[i], OUTPUT);  // initialiseer alle lagen als output d.m.v een for-loop
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  LayerOneByOne();  // voer LayerOneByOne uit
  Layers();  // voer Layers uit
  TurnOffLayers();  // voer TurnOffLayers uit
  delay(20);  // wacht 100ms
  FlickerFaster();  // voer FlickerFaster uit
  delay(50);  // wacht 20ms
  ColumnsOff();  // voer ColumnsOff uit
  delay(200);  // wacht 200ms
  ColumnsOnOff();  // voer ColumnsOnOff uit
  delay(200);  // wacht 200ms
  OneByOneUpDown();  // voer OneByOneUpDown uit
  delay(200);  // wacht 200ms
  RandomRain();  // voer RandomRain uit
  delay(200);  // wacht 200ms
  OneByOneRandom();  // voer OneByOneRandom uit
  delay(10000);  // wacht 100000ms
  // einde programma
}


void Layers() {  // maak sub-programma Layers aan
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(Column[i], 0);  // Stuur alle kolommen laag d.m.v. een for-loop
  }
  for (int j = 0; j < 4; j++) {
    digitalWrite(Layer[j], 1);  // Stuur de lagen een voor een hoog, d.m.v. een for-loop
    delay(100);  // wacht 100ms
}
}
void TurnOffLayers() {  // maak sub-programma TurnOffLayers aan
  for (int i = 0; i < 16; i++) {
    digitalWrite(Column[i], 0);  // Stuur alle kolommen laag d.m.v. een for-loop
  }
  for (int j = 4; j >= 0; j--) {
    digitalWrite(Layer[j], 0);  // Stuur alle lagen laag d.m.v. een for-loop
    delay(100);
  }
}

void LayerOneByOne(){  // maak sub-programma LayerOneByOne aan
  TurnOn(); // roep programma TurnOn op
  for (int i = 0; i <= 3; i++) { // stuur elke laag aan d.m.v.
    digitalWrite(Layer[i], 1); // stuur "i" aan dir wordt bij elke loop verhoogd
    for (int j = 0; j < 16; j++) { // stuur elke individuele LED aan d.m.v. een for-loop in de for-loop van layers     digitalWrite(Column[j], 0);
      delay(75); // wacht 75 ms
      digitalWrite(Column[j], 1); // stuur "j" aan dit wordt bij elke loop verhoogd 
      delay(75); // wacht 75 ms
  }
    digitalWrite(Layer[i], 0); // zet elke layer terug uit
  }
}

void ColumnsOff() {  // maak sub-programma ColumnsOff aan
  for (int i = 0; i < 16; i++) { // maak een for-loop voor elke kolom
    digitalWrite(Layer[0], 1); // zet laag 1 hoog
    digitalWrite(Layer[1], 1); // zet laag 2 hoog
    digitalWrite(Layer[2], 1); // zet laag 3 hoog
    digitalWrite(Layer[3], 1); // zet laag 4 hoog
    digitalWrite(Column[i], 1); // zet elke kolom hoog, d.m.v. de for-loop
    delay(100); // wacht 100ms na elke loop
  }
}

void TurnOn() {  // maak sub-programma TurnOn aan
  for (int i = 0; i < 16; i++) { // maak een for-loop voor elke kolom
    digitalWrite(Column[i], 0); // stuur elke kolom laag d.m.v de for-loop
  }
  for (int i = 0; i < 4; i++) { // maak een for-loop voor elke layer
    digitalWrite(Layer[i], 1); // stuur elke layer aan d.m.v. de for-loop
  }
}

void TurnOff() {  // maak sub-programma TurnOff aan
  for (int i = 0; i < 16; i++) { // maak een for-loop voor elke kolom
    digitalWrite(Column[i], 1); // stuur elke kolom hoog d.m.v de for-loop
  }
  for (int i = 0; i < 4; i++) { // maak een for-loop voor elke layer
    digitalWrite(Layer[i], 0); // stuur elke layer laag d.m.v de for-loop
  }
}

void FlickerFaster() {  // maak sub-programma FlickerFaster aan
  int i = 150; // stel getal i gelijk aan 150
  while (i != 1) // wanneer i niet 1 is:
  {
    TurnOn(); // roep TurnOn op
    delay(i); // wacht met waarde i
    TurnOff(); // roep TurnOff op
    delay(i); // wacht weer met waarde i
    i -= 5; // er wordt 5 van i afgetrokken voor elke loop
    if (i <= 5) { // als i kleiner of gelijk aan 5 is:
      i = 1; // wordt i gelijkgesteld aan 1 om uit de while-loop te komen
    }
  }
}
void RandomRain(){  // maak sub-programma RandomRain aan
  TurnOff(); // roep TurnOff op
  int x = 100; // stel getal x gelijk aan 100
  for (int i = 0; i != 60; i += 2) // maak een for-loop aan waarbij i elke keer met 2 wordt opgeteld en i niet gelijk mag zijn aan 60
  {
    int randomColumn = random(0, 16); // de variabele RandomColumn is gelijk aan een random getal tussen 0 en 16
    digitalWrite(Column[randomColumn], 0); // zet RandomColumn laag
    digitalWrite(Layer[0], 1); // zet de eerste layer hoog
    delay(x + 50); // wacht x+50 ms
    digitalWrite(Layer[0], 0); // zet layer 1 laag
    digitalWrite(Layer[1], 1); // zet layer 2 hoog
    delay(x); // wacht x ms
    digitalWrite(Layer[1], 0); // zet layer 2 laag
    digitalWrite(Layer[2], 1); // zet layer 3 hoog
    delay(x); // wacht x ms
    digitalWrite(Layer[2], 0); // zet layer 3 laag
    digitalWrite(Layer[3], 1); // zet layer 4 hoog
    delay(x + 50); // wacht x + 50 ms
    digitalWrite(Layer[3], 0); // zet layer 4 laag
    digitalWrite(Column[randomColumn], 1); // zet randomColumn hoog
  }
}

void OneByOneUpDown(){  // maak sub-programma OneByOneUpDown aan
  int x = 50; // stel getal x gelijk aan 50
  TurnOff(); // roep TurnOff op
  for (int y = 0; y < 2; y++) // deze loop is enkel zodat die dit sub-programma tweemaal uitvoert
  {
    //0-3
    for (int count = 4; count != 0; count--) // voor variable count met startwaarde 4, laat je count zakken met 1, maar hij mag nooit 0 worden
    {
      digitalWrite(Layer[count - 1], 1); // zet layer van waarde count - 1 hoog
      for (int i = 0; i < 4; i++) // maak een for-loop voor Columns 0-3
      {
        digitalWrite(Column[i], 0); // zet kolom i laag
        delay(x); // wacht x ms
        digitalWrite(Column[i], 1); // zet kolom i hoog
        delay(x); // wacht x ms
      }
      digitalWrite(Layer[count - 1], 0); // zet layer count - 1 laag
    }
    //4-7
    for (int count = 0; count < 4; count++) // maar weer een for-loop aan met count, voor kolom 4-7 waarbij count optelt
    {
      digitalWrite(Layer[count], 1); // zet layer count hoog
      for (int i = 4; i < 8; i++) // maak een for-loop aan voor Columns 4-7
      {
        digitalWrite(Column[i], 0); // zet column i laag
        delay(x); // wacht x ms
        digitalWrite(Column[i], 1); // zet column i hoog
        delay(x); // wacht x ms
      }
      digitalWrite(Layer[count], 0); // zet layer count laag
    }
    //8-11
    for (int count = 4; count != 0; count--) // maak weer een for-loop aan met count voor 8-11 waarbij count daalt
    {
      digitalWrite(Layer[count - 1], 1); // stuur layer count - 1 hoog
      for (int i = 8; i < 12; i++) // maak een for-loop om Columns 8-11 aan te sturen
      {
        digitalWrite(Column[i], 0); // zet Column i laag
        delay(x); // wacht x ms
        digitalWrite(Column[i], 1); // zet Column i hoog
        delay(x); // wacht x ms
      }
      digitalWrite(Layer[count - 1], 0); // zet laag count - 1 laag
    }
    //12-15
    for (int count = 0; count < 4; count++) // maak een for-loop met count aan voor 12-15 waarbij count optelt
    {
      digitalWrite(Layer[count], 1); // stur layer count hoog
      for (int i = 12; i < 16; i++) // maak een for-loop voor Column 12-16 aan te sturen
      {
        digitalWrite(Column[i], 0); // zet Column i laag
        delay(x); //wacht x ms
        digitalWrite(Column[i], 1); // zet Column i hoog
        delay(x); // wacht x ms
      }
      digitalWrite(Layer[count], 0); // zet Layer count laag
    }
  }
}

void ColumnsOnOff(){  // maak sub-programma ColumnsOnOff aan
  int x = 75; // stel getal x gelijk aan 75
  TurnOff(); // roep TurnOff op
  //turn on layers
  for (int i = 0; i < 4; i++) // maak een for-loop met i waarbij i kleiner blijft dan 4 en telkens wordt opgeteld met 1
  {
    digitalWrite(Layer[i], 1); // zet layer i hoog
  }
  for (int y = 0; y < 2; y++) // deze for-loop is puur om het volgende 3x uit te voeren
  {
    //turn on 0-3
    for (int i = 0; i < 4; i++) // maak een for-loop aan voor Columns 0-3 hoog te sturen
    {
      digitalWrite(Column[i], 0); // zet Column i laag
      delay(x); // wacht x ms
    }
    //turn on 4-7
    for (int i = 4; i < 8; i++) // maak een for-loop aan voor Columns 4-7 hoog te sturen
    {
      digitalWrite(Column[i], 0); // zet Column i laag
      delay(x); // wacht x ms
    }
    //turn on 8-11
    for (int i = 8; i < 12; i++) // maak een for-loop aan voor Columns 8-11 hoog te sturen
    {
      digitalWrite(Column[i], 0); // zet Column i laag
      delay(x); // wacht x ms
    }
    //turn on 12-15
    for (int i = 12; i < 16; i++) // maak een for-loop aan voor Columns 12-15 hoog te sturen
    {
      digitalWrite(Column[i], 0); // zet Column i laag
      delay(x); // wacht x ms
    }
    //turn off 0-3
    for (int i = 0; i < 4; i++) // maak een for-loop aan voor Columns 0-3 laag te sturen
    {
      digitalWrite(Column[i], 1); // zet column i hoog
      delay(x); // wacht x ms
    }
    //turn off 4-7
    for (int i = 4; i < 8; i++) // maak een for-loop aan voor Columns 4-7 laag te sturen
    {
      digitalWrite(Column[i], 1); // zet column i hoog
      delay(x); // wacht x ms
    }
    //turn off 8-11
    for (int i = 8; i < 12; i++) // maak een for-loop aan voor Columns 8-11 laag te sturen
    {
      digitalWrite(Column[i], 1); // zet column i hoog
      delay(x); // wacht x ms
    }
    //turn off 12-15
    for (int i = 12; i < 16; i++) // maak een for-loop aan voor Columns 12-15 laag te sturen
    {
      digitalWrite(Column[i], 1); // zet column i hoog
      delay(x); // wacht x ms
    }
    //turn on 12-15
    for (int i = 12; i < 16; i++) // maak een for-loop aan voor Columns 12-15 hoog te sturen
    {
      digitalWrite(Column[i], 0); // zet column i laag
      delay(x); // wacht x ms
    }
    //turn on 8-11
    for (int i = 8; i < 12; i++) // maak een for-loop aan voor Columns 8-11 hoog te sturen
    {
      digitalWrite(Column[i], 0); // zet column i laag
      delay(x); // wacht x ms
    }
    //turn on 4-7
    for (int i = 4; i < 8; i++) // maak een for-loop aan voor Columns 4-7 hoog te sturen
    {
      digitalWrite(Column[i], 0); // zet column i laag
      delay(x); // wacht x ms
    }
    //turn on 0-3
    for (int i = 0; i < 4; i++) // maak een for-loop aan voor Columns 0-3 hoog te sturen
    {
      digitalWrite(Column[i], 0); // zet column i laag
      delay(x); // wacht x ms
    }
    //turn off 12-15
    for (int i = 12; i < 16; i++) // maak een for-loop aan voor Columns 12-15 laag te sturen
    {
      digitalWrite(Column[i], 1); // zet column i hoog
      delay(x); // wacht x ms
    }
    //turn off 8-11
    for (int i = 8; i < 12; i++) // maak een for-loop aan voor Columns 8-11 laag te sturen
    {
      digitalWrite(Column[i], 1); // zet column i hoog
      delay(x); // wacht x ms
    }
    //turn off 4-7
    for (int i = 4; i < 8; i++) // maak een for-loop aan voor Columns 4-7 laag te sturen
    {
      digitalWrite(Column[i], 1); // zet column i hoog
      delay(x); // wacht x ms
    }
    //turn off 0-3
    for (int i = 0; i < 4; i++) // maak een for-loop aan voor Columns 0-3 laag te sturen
    {
      digitalWrite(Column[i], 1); // zet column i hoog
      delay(x); // wacht x ms
    }
  }
}

void OneByOneRandom(){  // maak sub-programma OneByOneRandom aan
  TurnOff(); // roep TurnOff op
  int x = 10; // stel getal x gelijk aan 10
  for (int i = 0; i != 750; i += 2) // maak een for-loop aan waarbij i een startwaarde van 0 heeft en nooit 750 mag worden, en wordt telkens met 2 opgeteld
  {
    int RandomLayer = random(0, 4); // variabele RandomLayer kiest een random getal tussen 0 en 4
    int RandomColumn = random(0, 16); // variabele RandomColumn kiest een random getal tussen 0 en 16

    digitalWrite(Layer[RandomLayer], 1); // stuur RandomLayer hoog
    digitalWrite(Column[RandomColumn], 0); // stuur RandomColumn laag
    delay(x); // wacht x ms
    digitalWrite(Layer[RandomLayer], 0); // stuur RandomLayer laag
    digitalWrite(Column[RandomColumn], 1); // stuur RandomColumn hoog
    delay(x); // wacht x ms
  }
}
