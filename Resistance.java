// Создаем класс activeresistance

class activeresistance {

    private double resistance;

    // Конструктор без параметров

    public activeresistance() {

        resistance = 0;

    }

    // Конструктор с параметром

    public activeresistance(double r) {

        resistance = r;

    }

    // Геттер для resistance

    public double getresistance() {

        return resistance;

    }

    // Сеттер для resistance

    public void setresistance(double r) {

        resistance = r;

    }

    // Метод для вывода активного сопротивления

    void showresistance() {

        System.out.println("активное сопротивление: " + resistance + " ом");

    }

}

// Создаем класс inductiveresistance, наследуемый от activeresistance

class inductiveresistance extends activeresistance {

    private double inductance;

    // Метод для расчета общего сопротивления (с учетом индуктивности)

    public double gettotalresistance() {

        return Math.sqrt(Math.pow(getresistance(), 2) + Math.pow(inductance, 2));

    }

    // Геттер для inductance

    public double getinductance() {

        return inductance;

    }

    // Сеттер для inductance

    public void setinductance(double i) {

        inductance = i;

    }

    // Метод для вывода индуктивного сопротивления

    void showinductance() {

        System.out.println("индуктивное сопротивление: " + inductance + " ом");

    }

}

// Создаем класс capacitiveresistance, наследуемый от activeresistance

class capacitiveresistance extends activeresistance {

    private double capacitance;

    // Метод для расчета общего сопротивления (с учетом емкости)

    public double gettotalresistance() {

        return 1 / Math.sqrt(Math.pow(getresistance(), 2) + Math.pow(1 / capacitance, 2));

    }

    // Геттер для capacitance

    public double getcapacitance() {

        return capacitance;

    }

    // Сеттер для capacitance

    public void setcapacitance(double c) {

        capacitance = c;

    }

    // Метод для вывода емкостного сопротивления

    void showcapacitance() {

        System.out.println("емкостное сопротивление: " + capacitance + " ф");

    }

}

// Создаем класс resistors

class resistors {

    public static void main(String args[]) {

        activeresistance r1 = new activeresistance(10.0);

        inductiveresistance r2 = new inductiveresistance();

        capacitiveresistance r3 = new capacitiveresistance();

        r2.setresistance(5.0);

        r2.setinductance(2.0);

        r3.setresistance(3.0);

        r3.setcapacitance(0.5);

        System.out.println("информация об r1: ");

        r1.showresistance();

        System.out.println("информация об r2: ");

        r2.showresistance();

        r2.showinductance();

        System.out.println("общее сопротивление: " + r2.gettotalresistance() + " ом");

        System.out.println("информация об r3: ");

        r3.showresistance();

        r3.showcapacitance();

        System.out.println("общее сопротивление: " + r3.gettotalresistance() + " ом");

    }

}

