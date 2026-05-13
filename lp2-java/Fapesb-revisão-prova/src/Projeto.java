import java.util.ArrayList;
import java.util.List;

public class Projeto {
    private String titulo;
    private String objetivo;
    private double duracao;
    private double valorBolsa;
    private Professor profResponsavel;
    private List<Aluno> alunos;
    private List<Material> materiais;
    
    public Projeto(String titulo, String objetivo, double duracao, double valorBolsa, Professor profResponsavel) {
        this.titulo = titulo;
        this.objetivo = objetivo;
        this.duracao = duracao;
        this.valorBolsa = valorBolsa;
        this.profResponsavel = profResponsavel;
        this.alunos = new ArrayList<Aluno>();
        this.materiais = new ArrayList<Material>();
    }
    
    public String getTitulo () {
        return this.titulo;
    }
    
    public void setTitulo (String titulo) {
        this.titulo = titulo;
    }
    
    public String getObjetivo () {
        return this.objetivo;
    }
    
    public void setObjetivo (String objetivo) {
        this.objetivo = objetivo;
    }
    
    public double getDuracao () {
        return this.duracao;
    }
    
    public void setDuracao (double duracao) {
        this.duracao = duracao;
    }
    
    public double getValorBolsa () {
        return this.valorBolsa;
    }
    
    public void setValorBolsa (double valorBolsa) {
        this.valorBolsa = valorBolsa;
    }
    
    public double calcularCusto () {
        double custoTotal = 0;
        
        for (Material m : materiais) {
            custoTotal += m.getValor(); 
        }
        
        for (Aluno a : alunos) {
            if (a.getBolsista()) {
                custoTotal += valorBolsa;
            }
        }
        
        return custoTotal;
    }
    
    public void imprimeDados () {
        System.out.println("================== PROJETO " + titulo + " ==================");
        System.out.println("PROFESSOR RESPONSAVEL: \nNome: " + profResponsavel.getNome() + "\nMatricula: " + profResponsavel.getMatricula());
        System.out.println("ALUNOS:");
        for (Aluno a : alunos) {
            if (a.getBolsista()) {
                System.out.println("Nome: " + a.getNome() + "\nCurso: " + a.getCurso() + "\nBolsa: R$ " + valorBolsa);
            } else {
                System.out.println("Nome: " + a.getNome() + "\nCurso: " + a.getCurso() + "\nVoluntario");
            }
        }
    }
}