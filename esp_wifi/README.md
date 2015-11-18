

# Esp8266 hookup

Esp8266 er i vår sammenheng flashet slik at den fungerer som en serial to wifi/http
chip. Det vil si at vi bruker et api som snakker med esp'en og som videre går ut
på internett.


Under kommer en beskrivelse av hvordan vi debuger og utvikler med esp.

## Første versjon - http://requestb.in/

 * gå til http://requestb.in/
 * trykk på "Create a RequestBin"
 * hent ut uri'en feks ""/z29mtnz2"
 * Bruk host og uri i sketchen.
 * Refresh siden når du mener du skal ha sendt noe til internett.


## Push til mobiltelefon

Dette er litt mer komplisert fordi det er flere ting som skal settes opp og snakke
sammen. Men vi gjør veldig lite av selve jobben. Følg listen så går det nok bra.

  * Lag en bruker og installer appen fra pushbullet
  * Lag en konto på https://ifttt.com
  * Trykk "new recipe"
  * Trykk på "this" i if this then that
  * Søk opp "maker channel"
  * Trykk connect og gjennomfør veiviser -> "continue to next step"
  * Velg "receive a web request"
  * Kall eventet ditt noe, dette skal brukes senere. Feks arduino
  * Trykk på "that" i if this then that
  * Søk opp pushbullet -> trykk "connect" -> logg inn med samme tjensete som da du laget pushbullet konto
  * Velg "push a note" og legge inn passende tekst
  * Avslutt veiviseren. Kanalen er nå laget. Nå kan den testes
  * Nå kan man gå til https://ifttt.com/maker og se hvordan dette fungerer.
  * Trykk på nøkkelen under "Your key is"
  * Kopier host(maker.ifttt.com) til variabelen host i arduino sketchen.
  * Fyll inn hva triggeren din heter og kopier uri fra curl kommandoen feks "/trigger/arduino/with/key/bo2ZvFAv9OLPG50qv3ziv7"
  * Nå kan du teste kanalen din ved å trykke "test it." Du kan også rekjøre sketchen for å pushe fra arduinoen.
