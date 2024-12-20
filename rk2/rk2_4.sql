CREATE TABLE products (
    id SERIAL PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    quantity INTEGER NOT NULL DEFAULT 0
);

CREATE TABLE operations_log (
    id SERIAL PRIMARY KEY,
    product_id INTEGER REFERENCES products(id),
    operation VARCHAR(10) NOT NULL CHECK (operation IN ('ADD', 'REMOVE')),
    quantity INTEGER NOT NULL,
);

CREATE OR REPLACE FUNCTION update_stock(product_id INT, operation VARCHAR, quantity INT) RETURNS VOID AS $$
BEGIN
    IF NOT EXISTS (SELECT 1 FROM products WHERE id = product_id) THEN
        RAISE EXCEPTION 'Product with id % does not exist', product_id;
    END IF;

    IF operation = 'ADD' THEN
        UPDATE products
        SET quantity = quantity + quantity
        WHERE id = product_id;

    ELSIF operation = 'REMOVE' THEN
        UPDATE products
        SET quantity = quantity - quantity
        WHERE id = product_id AND quantity >= quantity;
    END IF;

    INSERT INTO operations_log (product_id, operation, quantity)
    VALUES (product_id, operation, quantity);
END;
$$ LANGUAGE plpgsql;
CREATE OR REPLACE FUNCTION log_operation() RETURNS TRIGGER AS $$
BEGIN
    INSERT INTO operations_log (product_id, operation, quantity)
    VALUES (NEW.id, TG_ARGV[0], NEW.quantity);
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER product_operations
AFTER INSERT OR UPDATE
ON products
FOR EACH ROW
EXECUTE FUNCTION log_operation();
INSERT INTO products (name, quantity) VALUES ('Product A', 50);

SELECT update_stock(1, 'ADD', 20);
SELECT update_stock(1, 'REMOVE', 10);
