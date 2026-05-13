import java.util.ArrayList;

public class Usuario
{
    private String login;
    private String senha;
    private String dataDeAtivacao;
    
    private ArrayList<App> meusApps;
    
    public Usuario (String login, String senha, String dataDeAtivacao) {
        this.login = login;
        this.senha = senha;
        this.dataDeAtivacao = dataDeAtivacao;
        this.meusApps = new ArrayList<App>();
    }
    
    public void adquirirApp (App novoApp) {
        meusApps.add(novoApp);
    }
    
    public double gastoMensal () {
        double valorTotal = 0;
        
        for (App aplicativo : meusApps) {
            valorTotal += aplicativo.getValorMensal();
        }
        
        return valorTotal;
    }
    
    public ArrayList<App> getMeusApps () {
        return this.meusApps;
    }
}