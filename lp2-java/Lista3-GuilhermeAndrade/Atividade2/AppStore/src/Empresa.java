public class Empresa
{
    private String cnpj;
    private String nome;
    private String telefone;
    
    public Empresa (String cnpj, String nome, String telefone) {
        this.cnpj = cnpj;
        this.nome = nome;
        this.telefone = telefone;
    }
    
    public String getNome () {
        return this.nome;
    }
}