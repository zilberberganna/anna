
class TwoDShape {
 double width;
 double height;
 TwoDShape() {
                width = 0;
                height = 0;
        }
 TwoDShape(double w, double h) {
  width = w;
  height = h;
 }

 void showDim() {
  System.out.println("Ширина фигуры: " + width + "\nВысота фигуры: " + height);
 }
}
class Triangle extends TwoDShape {
 String style;

 double area() {
  return width * height / 2;
 }

 void showStyle() {
  System.out.println("Треугольник " + style);
 }
}
class Rectangle extends TwoDShape {
 String outside;

 double area() {
  return width * height;
 }

 void showOutside() {
                System.out.println("Прямоугольник " + outside);
        }

}
class Figures {
 public static void main(String args[]) {
  TwoDShape f1 = new TwoDShape(3.0, 5.0);
  Triangle f2 = new Triangle();
  Rectangle f3 = new Rectangle();
  System.out.println("Информация об f1:  ");
  f1.showDim();
  System.out.println("Информация об f2:  ");
  f2.showDim();
  System.out.println("Площадь: " + f2.area());
  System.out.println("Информация об f3:  ");
  f3.showDim();
  System.out.println("Площадь: " + f3.area());


 }
}






class Strings {
 public static void main(String args[]) {
  String str1 = "Первая строка";
  String str2 = new String(str1);
  String str3 = "Третья строка";
  int result, idx;
  char ch;

  System.out.println("Длина строки str1: " + str1.length());
  //Посимвольный вывод строки на экран
  for(int i = 0; i < str1.length(); i++)
   System.out.print(str1.charAt(i));
  System.out.println();
  if(str1.equals(str2))
   System.out.println("str1 и str2 эквивалентны");
  else
   System.out.println("str1 и str2 не эквивалентны");

  if(str1.equals(str3))
                        System.out.println("str1 и str3 эквивалентны");
                else
                        System.out.println("str1 и str3 не эквивалентны");

  result = str1.compareTo(str3);
  if(result == 0)
   System.out.println("str1 и str3 равны");
  else if(result < 0)
   System.out.println("str1 меньше, чем str3");
  else
   System.out.println("str1 больше, чем str3");
  String str4 = "Строка для поиска подстроки. Значения: подстрока 1, подстрока 2, подстрока 3";
  idx = str4.indexOf("подстрока");
  System.out.println("Индекс первого вхождения слова \"подстрока\": " + idx);
  idx = str4.lastIndexOf("подстрока");
  System.out.println("Индекс последнего вхождения слова \"подстрока\": "  + idx);






 }
}
