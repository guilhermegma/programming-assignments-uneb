import java.util.ArrayList;
import java.util.List;

public class Administradora {
    private String bandeira;
    private List<Cliente> clientes;

    public Administradora(String bandeira) {
        this.bandeira = bandeira;
        this.clientes = new ArrayList<Cliente>();
    }

    public Cliente obterClienteComMaisPontos() {
        if (clientes.isEmpty()) {
            return null;
        }
        Cliente maiorCliente = clientes.get(0);
        for (Cliente cliente : clientes) {
            if (cliente.obterTotalPontosAcumulados() > maiorCliente.obterTotalPontosAcumulados()) {
                maiorCliente = cliente;
            }
        }
        return maiorCliente;
    }

    public String getBandeira() {
        return bandeira;
    }

    public void setBandeira(String bandeira) {
        this.bandeira = bandeira;
    }

    public List<Cliente> getClientes() {
        return clientes;
    }

    public void adicionarCliente(Cliente cliente) {
        this.clientes.add(cliente);
    }
}