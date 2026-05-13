public class Produtos {

    private String codBarras;
    private String nome;
    private double valorCusto;
    private double valorVenda;
    private int estoque;

    public Produtos(String codBarras, String nome, double valorCusto, int estoque) {
        this.codBarras = codBarras;
        this.nome = nome;
        this.valorCusto = valorCusto;
        this.estoque = estoque;
    }

    public double venda (double porcentagemLucro) {
        if (porcentagemLucro <= 1){ //se o usuário digitar 0.50 (para 50%)
            valorVenda = valorCusto + (valorCusto * porcentagemLucro);
            System.out.println("A margem de lucro é de: " + porcentagemLucro * 100 + "%");
        }
        else if (porcentagemLucro > 1){ //se o usuário digitar 50 (para 50%)
            valorVenda = valorCusto + (valorCusto * (porcentagemLucro/100));
            System.out.println("A margem de lucro é de: " + porcentagemLucro + "%");
        }

        return valorVenda;
    }

    public int adicionarEstoque (int adicionar) {
        if (adicionar >= 0){
            estoque += adicionar;
            System.out.println("Quantidade adicionada: " + adicionar);
        }

        return estoque;
    }

    public int removerEstoque (int remover) {
        if (remover >= estoque){
            estoque = 0;
            System.out.println("O estoque foi zerado.");
        }
        else if (remover >= 0){
            estoque -= remover;
            System.out.println("A quantidade removida foi: " + remover);
        }

        return estoque;
    }
}