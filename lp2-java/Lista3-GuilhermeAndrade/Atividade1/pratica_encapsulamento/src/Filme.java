public class Filme {
    // Atributos privados, impedindo alterar de maneira externa
    private String nome;
    private int anoLancamento;
    private boolean disponivel;

    public Filme(String nome, int anoLancamento) {
        this.nome = nome;
        this.anoLancamento = anoLancamento;
        this.disponivel = true; // Filmes começam disponíveis
    }

    // GET aplicado para verificar o status
    public boolean getDisponibilidade() {
        return this.disponivel;
    }

    public void locarFilme() {
        if (getDisponibilidade()) {
            this.disponivel = false;
            System.out.println("Filme locado com sucesso!");
        } else {
            System.out.println("Este filme já está locado.");
        }
    }

    public void devolverFilme() {
        this.disponivel = true;
    }
}