import java.time.LocalDate;

public class Livros
{
    private String titulo;
    private String autor;
    private String editora;
    private String genero;
    private int ano;
    private int paginas;
    private String geracao;
    private String diasLocado;
    
    public Livros(String titulo, String autor, String editora, String genero, int ano, int paginas) {
        this.titulo = titulo;
        this.autor = autor;
        this.editora = editora;
        this.genero = genero;
        this.ano = ano;
        this.paginas = paginas;
    }
    
    public String geracao() {
        int anoAtual = LocalDate.now().getYear();
        
        if (anoAtual - ano > 500) {
            geracao = "Antigo";
        }
        else if (anoAtual - ano >= 100) {
            geracao = "Tradicional";
        }
        else {
            geracao = "Moderno";
        }
        
        return geracao;
    }
    
    public String diasLocacao () {
        if (paginas <= 50) {
            diasLocado = "4 dias para a devolução.";
        }
        else if (paginas > 50 && paginas <=300) {
            diasLocado = "1 semana para a devolução";
        }
        else if (paginas > 300) {
            diasLocado = "2 semanas para a devolução";
        }
        
        return diasLocado;
    }
}