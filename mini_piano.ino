int buzzer = 2; // Pino do buzzer / Buzzer pin
int led = 4; // Pino do LED de funcionamento / Status LED pin

const int botoes[] = {13, 12, 11, 10, 9, 8, 7}; // Pinos dos botões / Button pins
const int notas[] = {261, 294, 329, 349, 392, 440, 493}; // Frequências das notas (Dó a Si) / Note frequencies (C to B)

void setup() {
  pinMode(buzzer, OUTPUT); // Define o buzzer como saída / Set buzzer as output
  pinMode(led, OUTPUT); // Define o LED como saída / Set LED as output

  for (int i = 0; i < 7; i++) {
    pinMode(botoes[i], INPUT_PULLUP); // Define botões como entrada com pull-up / Set buttons as input with pull-up
  }
}

void loop() {
  bool notaTocada = false; // Flag para verificar se uma nota foi tocada / Flag to check if a note was played

  for (int i = 0; i < 7; i++) {
    if (digitalRead(botoes[i]) == LOW) { // Verifica se o botão foi pressionado / Check if button is pressed
      digitalWrite(led, HIGH); // Liga o LED / Turn on LED
      tone(buzzer, notas[i]); // Toca a nota correspondente / Play corresponding note
      delay(350); // Aguarda 350 ms / Wait 350 ms
      noTone(buzzer); // Para o som / Stop sound
      delay(10); // Pequena pausa / Small delay
      notaTocada = true;
      break;
    }
  }

  if (!notaTocada) {
    digitalWrite(led, LOW); // Desliga o LED / Turn off LED
    noTone(buzzer); // Garante que o som pare / Ensure sound is off
  }
}