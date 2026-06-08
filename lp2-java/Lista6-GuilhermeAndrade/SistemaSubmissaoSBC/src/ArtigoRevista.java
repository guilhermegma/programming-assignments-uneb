public class ArtigoRevista extends ArtigoLongo {

    public ArtigoRevista(String titulo, String resumo, String textoCompleto, int qtdPaginas) {
        super(titulo, resumo, textoCompleto, qtdPaginas);
    }

    @Override
    public double calcularTaxa() {
        return (this.getQtdPaginas() * 10.0) * 1.15;
    }
}
