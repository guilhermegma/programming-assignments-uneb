public class ArtigoCongresso extends ArtigoLongo {
    private String areaInteresse;

    public ArtigoCongresso(String titulo, String resumo, String textoCompleto, int qtdPaginas, String areaInteresse) {
        super(titulo, resumo, textoCompleto, qtdPaginas);
        this.areaInteresse = areaInteresse;
    }

    @Override
    public double calcularTaxa() {
        return this.getQtdPaginas() * 10.0;
    }

    public String getAreaInteresse() {
        return this.areaInteresse;
    }

    public void setAreaInteresse(String areaInteresse) {
        this.areaInteresse = areaInteresse;
    }
}
