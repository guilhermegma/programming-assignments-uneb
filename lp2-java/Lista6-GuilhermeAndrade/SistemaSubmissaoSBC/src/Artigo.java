import java.util.ArrayList;
import java.util.List;

public abstract class Artigo {
    private String titulo;
    private String resumo;
    private List<Pesquisador> autores;

    public Artigo(String titulo, String resumo) {
        this.titulo = titulo;
        this.resumo = resumo;
        this.autores = new ArrayList<Pesquisador>();
    }

    public abstract double calcularTaxa();

    public String getTitulo() {
        return this.titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String getResumo() {
        return this.resumo;
    }

    public void setResumo(String resumo) {
        this.resumo = resumo;
    }

    public List<Pesquisador> getAutores() {
        return this.autores;
    }

    public void adicionarAutor(Pesquisador autor) {
        this.autores.add(autor);
    }
}
