#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3);
float number1 = 0;
float number2 = 0;
int previousAnalog;
char operation = 'n';
int i = 0;
bool isDecimalPointOn = false;
// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
 
  lcd.clear();
}

// the loop routine runs over and over again forever:
void loop() {
  lcd.setCursor(0,0);
     int analog = analogRead(A0);
  if(analog != 0 && previousAnalog != analog){
    if(analog == 82){//key #1
      numberDisplay(1);
    }
    else if(analog == 81){//key #4
      numberDisplay(4);
    }
    else if(analog == 80){//key #7
      numberDisplay(7);
    }
    else if(analog == 79){//decimal point
      isDecimalPointOn =true;
    }
    else if(analog == 154){//key #2
      numberDisplay(2);
    }
    else if(analog == 153){//key #5
      numberDisplay(5);
    }
    else if(analog == 152){//key #8
      numberDisplay(8);
    }
    else if(analog == 150){//key #0
      numberDisplay(0);
    }
    else if(analog == 222){//key #3
      numberDisplay(3);
    }
    else if(analog == 221){//key #6
      numberDisplay(6);
    }
    else if(analog == 219){//key #9
      numberDisplay(9);
    }
    else if(analog == 217){
	
      number1 *= -1;
      lcd.print(number1, i);  
      
    }
    else if(analog == 289){//clear key
      number1 = 0;
      lcd.clear();
    }
    else if(analog == 288){//add key
      number2 += number1;
      number1 = 0;
      operation = '+';
      lcd.clear();
    }
    else if(analog == 286){//multiply
      (number2 == 0)? number2 = number1 : number2 *= number1;
      number1 = 0;
      operation = '*';
      lcd.clear();
    }
    else if(analog == 283){//panic
      
    }
    else if(analog == 359){//clear equation
      number1 = 0;
      number2 = 0;
      lcd.clear();
    }
    else if(analog == 358){//subtract
      number2 = number2 - number1;
      number1 = 0;
      operation = '-';
      lcd.clear();
    }
    else if(analog == 354){//divide
      number2 = number2 / number1;
      number1 = 0;
      operation = '/';
      lcd.clear();
    }
    else if(analog == 351){//equals
      switch(operation){
        
        case '+':
        number2 += number1; 
        lcd.print(number2); 
        break;
        case '*':
        number2 *= number1; 
        lcd.print(number2); 
        break;
        case '-':
        number2 = number2 - number1; 
        lcd.print(number2); 
        break;
        case '/':
        number2 = number2 / number1; 
        lcd.print(number2); 
        break;
        default:
        lcd.print(number1);
      }
    }
 }
 
  previousAnalog = analog;
    
  delay(75);
  
}

void numberDisplay(int number){
  int byteValue;
  if((lcd.print(number1) < 10)){
    lcd.clear();
    lcd.setCursor(0,0);
    if(!isDecimalPointOn){
      lcd.clear();
    lcd.setCursor(0,0);
  			number1 = number1 * 10 + number;
    	}
    if(isDecimalPointOn && (lcd.print(number1) < 10)){
      lcd.clear();
    lcd.setCursor(0,0);
      		i++;
      		number1 = number * pow(10, -i) + number1;
    	}
  
    byteValue = lcd.print(number1, i);

  }
}
