public abstract class ArtigoLongo extends Artigo {
    private String textoCompleto;
    private int qtdPaginas;

    public ArtigoLongo(String titulo, String resumo, String textoCompleto, int qtdPaginas) {
        super(titulo, resumo);
        this.textoCompleto = textoCompleto;
        this.qtdPaginas = qtdPaginas;
    }

    public String getTextoCompleto() {
        return this.textoCompleto;
    }

    public void setTextoCompleto(String textoCompleto) {
        this.textoCompleto = textoCompleto;
    }

    public int getQtdPaginas() {
        return this.qtdPaginas;
    }

    public void setQtdPaginas(int qtdPaginas) {
        this.qtdPaginas = qtdPaginas;
    }
}
