public class Encomenda
{
    private String codigo;
    private String remetente;
    private String destinatario;
    private String endereco;
    private int cep;
    private boolean nacional;
    private double peso;
    
    public Encomenda (String codigo, String remetente, String destinatario, String endereco, int cep, boolean nacional, double peso) {
        this.codigo = codigo;
        this.remetente = remetente;
        this.destinatario = destinatario;
        this.endereco = endereco;
        this.cep = cep;
        this.nacional = nacional;
        this.peso = peso;
    }
    
    public Encomenda (String codigo, String remetente, String destinatario, String endereco, int cep, double peso) {
        this.codigo = codigo;
        this.remetente = remetente;
        this.destinatario = destinatario;
        this.endereco = endereco;
        this.cep = cep;
        this.peso = peso;
        this.nacional = true;
    }
    
    public double postarEncomenda () {
        double valor = 0;

        if (peso <= 0.100) {
            valor = 2.50;
        } else if (peso <= 0.400) {
            valor = 12.00;
        } else {
            int excesso = (int)((peso - 0.400) * 1000);
            int blocos = (excesso + 99) / 100; //para identificar quantas vezes 1 real sera adicionado
            
            valor = 12.00 + (blocos * 1.00);
        }

        if (nacional == false) {
            valor += valor * 0.15;
        }
        return valor;
    }
}