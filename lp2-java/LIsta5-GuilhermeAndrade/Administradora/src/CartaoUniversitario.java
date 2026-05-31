import java.util.Date;

public class CartaoUniversitario extends Cartao {
    private String instituicaoEnsino;

    public CartaoUniversitario(String codigoPrincipal, String codigoSeguranca, Date dataExpedicao, Date dataValidade, String instituicaoEnsino) {
        super(codigoPrincipal, codigoSeguranca, dataExpedicao, dataValidade, 300.00);
        this.instituicaoEnsino = instituicaoEnsino;
    }

    public double calcularPontosPorValor(double valor) {
        return valor * 1.0;
    }

    public String getInstituicaoEnsino() {
        return instituicaoEnsino;
    }

    public void setInstituicaoEnsino(String instituicaoEnsino) {
        this.instituicaoEnsino = instituicaoEnsino;
    }
}