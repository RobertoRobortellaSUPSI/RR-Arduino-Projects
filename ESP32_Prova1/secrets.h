#include <pgmspace.h>

#define SECRET
#define THINGNAME "ESP32_Prova1"

const char WIFI_SSID[] = "GalaxyRR";
const char WIFI_PASSWORD[] = "GalaxyRR";
const char AWS_IOT_ENDPOINT[] = "a104rdfmtvdtuu-ats.iot.eu-west-2.amazonaws.com";

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
-----END RSA PRIVATE KEY-----
)KEY";
