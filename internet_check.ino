#include "WiFi.h"

#define led 2
 
const char* ssid1 ="ACTS-AP1";
const char* ssid2 ="ACTS-AP2";

const char* password ="";

 
void setup() {

  pinMode(led,OUTPUT);
  Serial.begin(115200);


  digitalWrite(led,HIGH); 
}

char check(const char* ssid, const char* password)
{
  WiFi.begin(ssid, password);
    int i=0; 
          Serial.println("Tring Connection to SSID.."+(String)ssid);
          while (WiFi.status() != WL_CONNECTED && i!=20) 
        {
          Serial.print(".");
          digitalWrite(led,HIGH);
          delay(100);
          digitalWrite(led,LOW); 
          
          delay(100);
          i++;
  
          if(i == 20)
          {
            return 'F';
          }
        }
  return 'T';
}

void con_confirm(char val,const char* ssid)
      {
        if(val == 'T')
        {
        Serial.println("Wifi is connected to--->"+(String)ssid);
        digitalWrite(led,HIGH);
        
        while(true);
        }                 
      }
      
void loop() {
      char val = 'F';
      val  =  check(ssid1,password);
      con_confirm(val,ssid1);
      val  = check(ssid2,password);
      con_confirm(val,ssid2);
    }
