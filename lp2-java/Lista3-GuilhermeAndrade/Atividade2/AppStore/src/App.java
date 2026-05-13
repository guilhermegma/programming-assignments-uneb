public class App
{
    private String nome;
    private String objetivo;
    private int tamanhoMb;
    private double valorMensal;
    private Empresa desenvolvedora;
    
    public App (String nome, String objetivo, int tamanhoMb, double valorMensal, Empresa desenvolvedora) {
        this.nome = nome;
        this.objetivo = objetivo;
        this.tamanhoMb = tamanhoMb;
        this.valorMensal = valorMensal;
        this.desenvolvedora = desenvolvedora;
    }
    
    public String getObjetivo () {
        return this.objetivo;
    }
    
    public double getValorMensal () {
        return this.valorMensal;
    }
    
    public boolean substituir (App segundoApp) {
        return this.objetivo.equals(segundoApp.getObjetivo()) &&
        this.valorMensal >= (segundoApp.getValorMensal());
    }
    
    public void imprimirDados () {
        System.out.println(
        "Nome do app: " + nome + 
        "\nObjetivo: " + objetivo + 
        "\nTamanho: " + tamanhoMb + 
        "Mb\nMensalidade: R$" + valorMensal + 
        "\nEmpresa: " + desenvolvedora.getNome());
    }
}