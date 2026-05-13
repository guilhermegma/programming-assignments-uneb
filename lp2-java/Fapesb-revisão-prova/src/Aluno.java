public class Aluno
{
    private String nome;
    private String curso;
    private boolean bolsista = false;
    
    public Aluno(String nome, String curso, boolean bolsista) {
        this.nome = nome;
        this.curso = curso;
        this.bolsista = bolsista;
    }
    
    public String getNome() {
        return this.nome;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }
    
    public String getCurso() {
        return this.curso;
    }
    
    public void setCurso(String curso) {
        this.curso = curso;
    }
    
    public boolean getBolsista () {
        return this.bolsista;
    }
    
    public void setBolsista (boolean bolsista) {
        this.bolsista = bolsista;
    }
}