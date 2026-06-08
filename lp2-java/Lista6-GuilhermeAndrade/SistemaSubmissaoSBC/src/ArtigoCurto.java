 public class ArtigoCurto extends Artigo {
    private String instituicao;

    public ArtigoCurto(String titulo, String resumo, String instituicao) {
        super(titulo, resumo);
        this.instituicao = instituicao;
    }

    @Override
    public double calcularTaxa() {
        return 4 * 10.0;
    }

    public String getInstituicao() {
        return this.instituicao;
    }

    public void setInstituicao(String instituicao) {
        this.instituicao = instituicao;
    }
}
