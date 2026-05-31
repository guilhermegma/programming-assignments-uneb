import java.util.Date;

public class CartaoOuro extends Cartao {

    public CartaoOuro(String codigoPrincipal, String codigoSeguranca, Date dataExpedicao, Date dataValidade) {
        super(codigoPrincipal, codigoSeguranca, dataExpedicao, dataValidade, 1000000.00);
    }

    public double calcularPontosPorValor(double valor) {
        return valor * 2.0;
    }
}