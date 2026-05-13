public class Passagem {
    private String identificador;
    private String origem;
    private String destino;
    private String dataHoraPartida;
    private String tipoPassagem; 
    private String cpfPassageiro;
    private int numeroAssento;
    private double precoBase;


    public Passagem(String identificador, String origem, String destino, String dataHoraPartida, String tipoPassagem, double precoBase) {
        this.identificador = identificador;
        this.origem = origem;
        this.destino = destino;
        this.dataHoraPartida = dataHoraPartida;
        this.tipoPassagem = tipoPassagem;
        this.precoBase = precoBase;
    }

    public Passagem(String identificador, String origem, String destino, String dataHoraPartida, String tipoPassagem, double precoBase, String cpfPassageiro) {
        this.identificador = identificador;
        this.origem = origem;
        this.destino = destino;
        this.dataHoraPartida = dataHoraPartida;
        this.tipoPassagem = tipoPassagem;
        this.precoBase = precoBase;
        this.cpfPassageiro = cpfPassageiro;
    }

    public void escolherAssento(int numeroAssento) {
        this.numeroAssento = numeroAssento;
    }

    public void cancelarPassagem() {
        this.numeroAssento = 0;
        this.cpfPassageiro = null;
    }

    public double calcularPassagem() {
        double precoFinal = precoBase;
        
        if (tipoPassagem.equalsIgnoreCase("economica")) {
            precoFinal += precoBase * 0.10;
        } else if (tipoPassagem.equalsIgnoreCase("executiva")) {
            precoFinal += precoBase * 0.50;
        } else if (tipoPassagem.equalsIgnoreCase("primeira classe")) {
            precoFinal += precoBase * 0.90;
        }
        
        return precoFinal;
    }

    public double calcularPassagem(double percentual) {
        double aux = 0;
        
        if (percentual > 1) {
            aux = precoBase * (percentual / 100);
        } else {
            aux = precoBase * percentual;
        }
        
        return precoBase + aux;
    }
}