import java.util.Date;

public class Compra {
    private String nomeEstabelecimento;
    private Date dataCompra;
    private Cartao cartao;
    private double valorTotal;
    private int quantidadeParcelas;

    public Compra(String nomeEstabelecimento, Date dataCompra, Cartao cartao, double valorTotal, int quantidadeParcelas) {
        this.nomeEstabelecimento = nomeEstabelecimento;
        this.dataCompra = dataCompra;
        this.cartao = cartao;
        this.valorTotal = valorTotal;
        this.quantidadeParcelas = quantidadeParcelas;
    }

    public double calcularPontosGanhos() {
        return this.cartao.calcularPontosPorValor(this.valorTotal);
    }

    public String getNomeEstabelecimento() {
        return nomeEstabelecimento;
    }

    public void setNomeEstabelecimento(String nomeEstabelecimento) {
        this.nomeEstabelecimento = nomeEstabelecimento;
    }

    public Date getDataCompra() {
        return dataCompra;
    }

    public void setDataCompra(Date dataCompra) {
        this.dataCompra = dataCompra;
    }

    public Cartao getCartao() {
        return cartao;
    }

    public void setCartao(Cartao cartao) {
        this.cartao = cartao;
    }

    public double getValorTotal() {
        return valorTotal;
    }

    public void setValorTotal(double valorTotal) {
        this.valorTotal = valorTotal;
    }

    public int getQuantidadeParcelas() {
        return quantidadeParcelas;
    }

    public void setQuantidadeParcelas(int quantidadeParcelas) {
        this.quantidadeParcelas = quantidadeParcelas;
    }
}