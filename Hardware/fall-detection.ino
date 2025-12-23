const int pinoTilt = 2;       // Pino do Tilt Switch
const int pinoBuzzer = 8;     // Pino do Buzzer
const int pinoLEDvermelho = 5; // Pino do Vermelho no LED RGB
const int pinoLEDverde = 6;   // Pino do Verde no LED RGB

// Variáveis para controle do estado
int estadoTilt = 0;           // Para ler o estado do tilt switch
bool alarmeAtivo = false;     // Flag para controlar se o alarme está ativo

// Variáveis para o piscar do LED (quando em alarme)
unsigned long tempoUltimoPisca = 0;
const unsigned long intervaloPisca = 500; // Intervalo para piscar o LED (ms)
bool estadoLED = false;

void setup() {
  // Inicializa os pinos
  pinMode(pinoTilt, INPUT);
  pinMode(pinoBuzzer, OUTPUT);
  pinMode(pinoLEDvermelho, OUTPUT);
  pinMode(pinoLEDverde, OUTPUT);

  // Inicia a comunicação serial para debug
  Serial.begin(9600);
  Serial.println("Monitor de Posição Corporal Iniciado.");
  Serial.println("Posição Normal: LED Verde.");
  Serial.println("Queda/Posição Incorreta: Alarme Vermelho e Sonoro.");

  // Inicia o sistema no estado "Seguro" (LED Verde aceso)
  digitalWrite(pinoLEDverde, HIGH);
  digitalWrite(pinoLEDvermelho, LOW);
  noTone(pinoBuzzer); // Garante que o buzzer está desligado
}

void loop() {
  // Lê o estado do tilt switch
  estadoTilt = digitalRead(pinoTilt);

  // Lógica principal baseada no estado do tilt
  if (estadoTilt == HIGH) {
    // Tilt switch FECHADO (Ex: objeto na posição vertical/normal)
    // Este é o estado SEGURO
    if (alarmeAtivo) {
      // Se o alarme estava ativo, desliga tudo
      desativarAlarme();
    }
    // Mantém o estado seguro (LED Verde aceso)
    digitalWrite(pinoLEDverde, HIGH);
    digitalWrite(pinoLEDvermelho, LOW);
    noTone(pinoBuzzer);

  } else {
    // Tilt switch ABERTO (Ex: objeto caído / na horizontal)
    // Este é o estado de ALARME
    if (!alarmeAtivo) {
      // Se o alarme não estava ativo, ativa ele
      ativarAlarme();
      Serial.println("ALARME! Posição incorreta detectada!");
    }
    // Executa a sequência de alarme (piscar LED vermelho e buzzer)
    executarAlarme();
  }

  // Pequena pausa para estabilidade
  delay(100);
}

void ativarAlarme() {
  alarmeAtivo = true;
  tempoUltimoPisca = millis(); // Inicia o timer para o pisca-pisca
  estadoLED = false;
  digitalWrite(pinoLEDverde, LOW); // Apaga o verde imediatamente
}

void desativarAlarme() {
  alarmeAtivo = false;
  digitalWrite(pinoLEDvermelho, LOW); // Garante que o vermelho está apagado
  noTone(pinoBuzzer);                 // Desliga o buzzer
  Serial.println("Alarme desativado. Posição normal restaurada.");
}

void executarAlarme() {
  unsigned long tempoAtual = millis();

  // Verifica se é hora de mudar o estado do LED/buzzer
  if (tempoAtual - tempoUltimoPisca >= intervaloPisca) {
    tempoUltimoPisca = tempoAtual; // Reinicia o timer
    estadoLED = !estadoLED;        // Inverte o estado do LED

    // Aplica o novo estado
    digitalWrite(pinoLEDvermelho, estadoLED ? HIGH : LOW);

    // O buzzer toca junto com o LED aceso
    if (estadoLED) {
      tone(pinoBuzzer, 800); // Toca um tom de 800Hz
    } else {
      noTone(pinoBuzzer);    // Silencia o buzzer
    }
  }
}
