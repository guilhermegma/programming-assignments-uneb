public class Cliente {
    private String cpf;
    private String nome;
    private String telefone;
    private Cartao cartao;

    public Cliente(String cpf, String nome, String telefone, Cartao cartao) {
        this.cpf = cpf;
        this.nome = nome;
        this.telefone = telefone;
        this.cartao = cartao;
    }

    public double obterTotalGastoComCartao() {
        return this.cartao.calcularTotalGasto();
    }

    public double obterTotalPontosAcumulados() {
        double totalPontos = 0;
        for (Compra compra : this.cartao.getCompras()) {
            totalPontos += compra.calcularPontosGanhos();
        }
        return totalPontos;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getTelefone() {
        return telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public Cartao getCartao() {
        return cartao;
    }

    public void setCartao(Cartao cartao) {
        this.cartao = cartao;
    }
}