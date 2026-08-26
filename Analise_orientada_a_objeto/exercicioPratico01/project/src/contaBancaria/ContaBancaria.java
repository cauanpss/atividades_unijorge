package contaBancaria;

public class ContaBancaria {

    private String titular;
    private double saldo;
    private int numeroConta;
    private static int contadorContas = 0;

    {
        System.out.println("Criando nova conta...");
    }

    public ContaBancaria (String titular, double saldoInicial){
        this.titular = titular;
        this.saldo = saldoInicial;
        this.numeroConta = ++contadorContas;
    }


}
