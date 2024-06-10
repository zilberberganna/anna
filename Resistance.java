class ActiveResistance {
    private double resistance;

    public ActiveResistance() {
        resistance = 0;
    }

    public ActiveResistance(double r) {
        resistance = r;
    }

    public double getResistance() {
        return resistance;
    }

    public void setResistance(double r) {
        resistance = r;
    }

    void showResistance() {
        System.out.println("Активное сопротивление: " + resistance + " Ом");
    }
}

class InductiveResistance extends ActiveResistance {
    private double inductance;

    public double getTotalResistance() {
        return Math.sqrt(Math.pow(getResistance(), 2) + Math.pow(inductance, 2));
    }

    public double getInductance() {
        return inductance;
    }

    public void setInductance(double i) {
        inductance = i;
    }

    void showInductance() {
        System.out.println("Индуктивное сопротивление: " + inductance + " Ом");
    }
}

class CapacitiveResistance extends ActiveResistance {
    private double capacitance;

    public double getTotalResistance() {
        return 1 / Math.sqrt(Math.pow(getResistance(), 2) + Math.pow(1 / capacitance, 2));
    }

    public double getCapacitance() {
        return capacitance;
    }

    public void setCapacitance(double c) {
        capacitance = c;
    }

    void showCapacitance() {
        System.out.println("Емкостное сопротивление: " + capacitance + " Ф");
    }
}

class Resistors {
    public static void main(String args[]) {
        ActiveResistance r1 = new ActiveResistance(10.0);
        InductiveResistance r2 = new InductiveResistance();
        CapacitiveResistance r3 = new CapacitiveResistance();

        r2.setResistance(5.0);
        r2.setInductance(2.0);

        r3.setResistance(3.0);
        r3.setCapacitance(0.5);

        System.out.println("Информация об r1: ");
        r1.showResistance();

        System.out.println("Информация об r2: ");
        r2.showResistance();
        r2.showInductance();
        System.out.println("Общее сопротивление: " + r2.getTotalResistance() + " Ом");

        System.out.println("Информация об r3: ");
        r3.showResistance();
        r3.showCapacitance();
        System.out.println("Общее сопротивление: " + r3.getTotalResistance() + " Ом");
    }
}