#define DHTPIN 15
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT11 sensor: ");
  dht.begin();
}

void loop() {
  // put yourmain code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if(isnan(h) || isnan(t)) {
    Serial.println("failed to read from dht sensor");
    return;
  }
  Serial.print("humidity: ");
  Serial.print(h);
  Serial.print(", ");
  Serial.print("temperature: ");
  Serial.println(t);
  delay(2000);
}
