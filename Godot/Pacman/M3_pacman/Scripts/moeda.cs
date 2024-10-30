using Godot;
using System;

public partial class moeda : Area2D
{
	
	public int ValorPonto = 10;
	public void Coletada(Node2D body) {
		jogador j;
		if (body is jogador) {
			j = (jogador)body;
			j.IncrementarPontuacao(ValorPonto);
		j.VerificarMoedas();
		QueueFree();
		}
		
	}
}
