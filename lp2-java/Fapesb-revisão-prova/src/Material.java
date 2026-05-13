public class Material {
    private String descricao;
    private double valor;
    
    public Material (String descricao, double valor) {
        this.descricao = descricao;
        this. valor = valor; 
    }
    
    public double getValor () {
        return this.valor;
    }
    
    public void setValor (double valor) {
        this.valor = valor;
    }
    
    public String getDescricao () {
        return this.descricao;
    }
    
    public void setDescricao (String descricao) {
        this.descricao = descricao;
    }
}