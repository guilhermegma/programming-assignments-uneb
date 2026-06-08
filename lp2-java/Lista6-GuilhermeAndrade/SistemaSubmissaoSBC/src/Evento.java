import java.util.ArrayList;
import java.util.List;

public class Evento {
    private String nome;
    private String periodo;
    private String dataLimiteSubmissao;
    private List<Artigo> artigosSubmetidos;

    public Evento(String nome, String periodo, String dataLimiteSubmissao) {
        this.nome = nome;
        this.periodo = periodo;
        this.dataLimiteSubmissao = dataLimiteSubmissao;
        this.artigosSubmetidos = new ArrayList<Artigo>();
    }

    public double calcularTotalArrecadado() {
        double total = 0;
        for (Artigo artigo : this.artigosSubmetidos) {
            total += artigo.calcularTaxa();
        }
        return total;
    }

    public int contarArtigosPorAutor(Pesquisador autor) {
        int contador = 0;
        for (Artigo artigo : this.artigosSubmetidos) {
            for (Pesquisador pesquisador : artigo.getAutores()) {
                if (pesquisador.getCpf().equals(autor.getCpf())) {
                    contador++;
                    break;
                }
            }
        }
        return contador;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getPeriodo() {
        return this.periodo;
    }

    public void setPeriodo(String periodo) {
        this.periodo = periodo;
    }

    public String getDataLimiteSubmissao() {
        return this.dataLimiteSubmissao;
    }

    public void setDataLimiteSubmissao(String dataLimiteSubmissao) {
        this.dataLimiteSubmissao = dataLimiteSubmissao;
    }

    public List<Artigo> getArtigosSubmetidos() {
        return this.artigosSubmetidos;
    }

    public void submeterArtigo(Artigo artigo) {
        this.artigosSubmetidos.add(artigo);
    }
}
