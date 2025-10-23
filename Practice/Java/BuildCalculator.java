import java.awt.*;
import java.awt.event;
import javax.swing.*;

class BuildCalculator extends JFrame implements ActionListener
{
    JFrame actualWindow;
    JPanel resultPanel, buttonPanel, infoPanel;

    JTextField resultTxt;
    JButton btn_digits[] = new JButton[10];
    JButton btn_plus, btn_minus, btn_mul, btn_div, btn_equal, btn_dot, btn_clear;
    char eventFrom;

    JLabel expression, appTile, siteTitle;

    double operand_1 = 0, operand_2 = 0;
    String operator = "=";

    BuildCalculator()
    {
        Font txtFont = new Font("Gothic", Font.BOLD, 20);
        Font titleFont = new Font("Gothic", Font.BOLD, 30);
        expressionFont = new Font("Gothic", Font.BOLD, 15);
        actualWindow = new JFrame("Calculator");
    }
}