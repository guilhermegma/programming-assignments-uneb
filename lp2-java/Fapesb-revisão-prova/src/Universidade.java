import java.util.ArrayList;
import java.util.List;

public class Universidade {
    private String nome;
    private String representante;
    private String telefone;
    private List<Projeto> projetos;
    
    public Universidade (String nome, String representante, String telefone) {
        this.nome = nome;
        this.representante = representante;
        this.telefone = telefone;
        this.projetos  = new ArrayList<Projeto>();
    }
    
    public String getNome() {
        return this.nome;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }
    
    public String getRepresentante() {
        return this.representante;
    }
    
    public void setRepresentante(String representante) {
        this.representante = representante;
    }
    
    public String getTelefone() {
        return this.telefone;
    }
    
    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }
}