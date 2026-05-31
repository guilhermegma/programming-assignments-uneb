import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public abstract class Cartao {
    private String codigoPrincipal;
    private String codigoSeguranca;
    private Date dataExpedicao;
    private Date dataValidade;
    protected double limite;
    private List<Compra> compras;

    public Cartao(String codigoPrincipal, String codigoSeguranca, Date dataExpedicao, Date dataValidade, double limite) {
        this.codigoPrincipal = codigoPrincipal;
        this.codigoSeguranca = codigoSeguranca;
        this.dataExpedicao = dataExpedicao;
        this.dataValidade = dataValidade;
        this.limite = limite;
        this.compras = new ArrayList<Compra>();
    }

    public abstract double calcularPontosPorValor(double valor);

    public double calcularTotalGasto() {
        double total = 0;
        for (Compra compra : compras) {
            total += compra.getValorTotal();
        }
        return total;
    }

    public String getCodigoPrincipal() {
        return codigoPrincipal;
    }

    public void setCodigoPrincipal(String codigoPrincipal) {
        this.codigoPrincipal = codigoPrincipal;
    }

    public String getCodigoSeguranca() {
        return codigoSeguranca;
    }

    public void setCodigoSeguranca(String codigoSeguranca) {
        this.codigoSeguranca = codigoSeguranca;
    }

    public Date getDataExpedicao() {
        return dataExpedicao;
    }

    public void setDataExpedicao(Date dataExpedicao) {
        this.dataExpedicao = dataExpedicao;
    }

    public Date getDataValidade() {
        return dataValidade;
    }

    public void setDataValidade(Date dataValidade) {
        this.dataValidade = dataValidade;
    }

    public double getLimite() {
        return limite;
    }

    public void setLimite(double limite) {
        this.limite = limite;
    }

    public List<Compra> getCompras() {
        return compras;
    }

    public void adicionarCompra(Compra compra) {
        if (this.calcularTotalGasto() + compra.getValorTotal() <= this.limite) {
            this.compras.add(compra);
        }
    }
}