using Godot;
using System;

public partial class diamante : Area2D
{
	public int ValorPonto = 10;
	public void Coletada(Node2D body) {
		jogadorFireboy j;
		if (body is jogadorFireboy) {
			j = (jogadorFireboy)body;
			j.IncrementarPontuacao(ValorPonto);
		QueueFree();
		}
		
	}
}
